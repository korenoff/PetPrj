
#include "Application.h"

#include <utility>


void Application::start() {
    Controller controller;
    IReader *reader = new ConsoleCommandReader;
    int user_command = controller.getCommand(reader);
    if (user_command == 2) {
        Application::load();
        delete reader;
        return;
    }
    if (user_command == 3) {
        Application::exit();
        delete reader;
        return;
    }

    bool is_file_logger = controller.isFileLogger(reader);
    bool is_console_logger = controller.isConsoleLogger(reader);
    bool is_trace_level, is_info_level, is_error_level;
    if (!is_file_logger and !is_console_logger) {
        is_trace_level = false;
        is_info_level = false;
        is_error_level = false;
    } else {
        is_trace_level = controller.isTraceLevel(reader);
        is_info_level = controller.isInfoLevel(reader);
        is_error_level = controller.isErrorLevel(reader);
    }
    Log *log = new Log{is_trace_level, is_info_level, is_error_level, is_file_logger, is_console_logger};

    controller.printUserInfo();

    game_observer->gameStarted(*log);

    InputCommands *file_input;
    file_input = new FileInputCommands;
    file_input->setObserver(*log);
    try{
        file_input->setCommands();
    } catch(const FileInputException &e){
        file_input->getObserver()->wrongData(std::string(e.what()));
    }

    GameDifficulty difficulty = controller.getGameDifficulty(reader, game_observer, *log);
    Field *field = nullptr;

    if (difficulty == GameDifficulty::MEDIUM) {
        FieldGenerator<BarrierRule<GameDifficulty::MEDIUM>, EnemyRule<GameDifficulty::MEDIUM>, FoodRule<GameDifficulty::MEDIUM>, MoneyRule<GameDifficulty::MEDIUM>, ExitPositionRule<GameDifficulty::MEDIUM>, TrapRule<GameDifficulty::MEDIUM>> generator1;
        field = generator1.createField(controller.getFieldHeight(reader, game_observer, *log),
                                       controller.getFieldWidth(reader, game_observer, *log), *log);
    } else {
        FieldGenerator<BarrierRule<GameDifficulty::EASY>, EnemyRule<GameDifficulty::EASY>, FoodRule<GameDifficulty::EASY>, MoneyRule<GameDifficulty::EASY>, ExitPositionRule<GameDifficulty::EASY>, TrapRule<GameDifficulty::EASY>> generator2;
        field = generator2.createField(controller.getFieldHeight(reader, game_observer, *log),
                                       controller.getFieldWidth(reader, game_observer, *log), *log);
    }

    field->setObserver(*log);


    PrintField print_field;
    Player player;
    if (difficulty == GameDifficulty::MEDIUM)
        player.setPointsToWin(200);
    player.setObserver(*log);

    print_field.print(*field);


    controller.printPlayerInfo(player);
    while (game) {
        controller.getAction(game, player, field, reader, file_input, log, game_observer);
        print_field.print(*field);
        controller.printPlayerInfo(player);
    }
    game_observer->gameEnded(*log);
    delete file_input;
    delete reader;
    delete field;
    delete log;
}

Application::Application() : game(true) {
    game_observer = new GameObserver;
}

Application::~Application() {
    delete game_observer;
}

void Application::load() {
    Controller controller;
    IReader *reader = new ConsoleCommandReader;
    Player player;
    try{
        controller.getIsFileValid();
    } catch(SaveException &e){
        std::cout << "[ERROR] Invalid file for load!\n";
        system("pause");
        return;
    } //!!!!!!!!exeption
    Log *log = nullptr;
    Field *field = nullptr;
    controller.loadData(game_observer, log);

    log = controller.loadLog();
    field = controller.loadField(*log);
    controller.loadPlayer(player);

    InputCommands *file_input;
    file_input = new FileInputCommands;
    controller.setFileInputObserver(log, file_input);
    file_input->setCommands();

    controller.setFieldObserver(field, log);

    PrintField print_field;
    controller.setPlayerObserver(player, log);

    print_field.print(*field);


    controller.printPlayerInfo(player);
    while (game) {
        controller.getAction(game, player, field, reader, file_input, log, game_observer);
        print_field.print(*field);
        controller.printPlayerInfo(player);
    }
    game_observer->gameEnded(*log);
    delete file_input;
    delete reader;
    delete log;
    delete field;
}

void Application::exit() {

}


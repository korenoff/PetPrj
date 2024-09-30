
#include "Controller.h"
#include <cmath>


void Controller::movePlayerUp(Field &field, Player &player) {
    PrintField print_field;
    if (!field.getCell((field.getHeight() + field.getActiveCellY() - 1) %
                       field.getHeight(), field.getActiveCellX()).getBarrier()) {
        field.moveUp(1, player);
    } else {
        throw PlayerMoveException(field.getActiveCellX(), field.getActiveCellY() - 1, " is barrier!");
    }
    print_field.print(field);
}

void Controller::movePlayerDown(Field &field, Player &player) {
    PrintField print_field;
    if (!field.getCell((field.getHeight() + field.getActiveCellY() + 1) %
                       field.getHeight(), field.getActiveCellX()).getBarrier()) {
        field.moveDown(1, player);
    } else {
        throw PlayerMoveException(field.getActiveCellX(), field.getActiveCellY() + 1, " is barrier!");
    }
    print_field.print(field);
}

void Controller::movePlayerRight(Field &field, Player &player) {
    PrintField print_field;
    if (!field.getCell(field.getActiveCellY(), (field.getWidth() + field.getActiveCellX() + 1) %
                                               field.getWidth()).getBarrier()) {
        field.moveRight(1, player);
    } else {
        throw PlayerMoveException(field.getActiveCellX() + 1, field.getActiveCellY(), " is barrier!");
    }
    print_field.print(field);
}

void Controller::movePlayerLeft(Field &field, Player &player) {
    PrintField print_field;
    if (!field.getCell(field.getActiveCellY(), (field.getWidth() + field.getActiveCellX() - 1) %
                                               field.getWidth()).getBarrier()) {
        field.moveLeft(1, player);
    } else {
        throw PlayerMoveException(field.getActiveCellX() - 1, field.getActiveCellY(), " is barrier!");
    }
    print_field.print(field);
}

void Controller::doubleMovePlayerUp(Field &field, Player &player) {
    PrintField print_field;
    if (!field.getCell((field.getHeight() + field.getActiveCellY() - 2) %
                       field.getHeight(), field.getActiveCellX()).getBarrier()) {
        field.moveUp(2, player);
    } else {
        throw PlayerMoveException(field.getActiveCellX(), field.getActiveCellY() - 2, " is barrier!");
    }
    print_field.print(field);
}

void Controller::doubleMovePlayerDown(Field &field, Player &player) {
    PrintField print_field;
    if (!field.getCell((field.getHeight() + field.getActiveCellY() + 2) %
                       field.getHeight(), field.getActiveCellX()).getBarrier()) {
        field.moveDown(2, player);
    } else {
        throw PlayerMoveException(field.getActiveCellX(), field.getActiveCellY() + 2, " is barrier!");
    }
    print_field.print(field);
}

void Controller::doubleMovePlayerRight(Field &field, Player &player) {
    PrintField print_field;
    if (!field.getCell(field.getActiveCellY(), (field.getWidth() + field.getActiveCellX() + 2) %
                                               field.getWidth()).getBarrier()) {
        field.moveRight(2, player);
    } else {
        throw PlayerMoveException(field.getActiveCellX() + 2, field.getActiveCellY(), " is barrier!");
    }
    print_field.print(field);
}

void Controller::doubleMovePlayerLeft(Field &field, Player &player) {
    PrintField print_field;
    if (!field.getCell(field.getActiveCellY(), (field.getWidth() + field.getActiveCellX() - 2) %
                                               field.getWidth()).getBarrier()) {
        field.moveLeft(2, player);
    } else {
        throw PlayerMoveException(field.getActiveCellX() - 2, field.getActiveCellY(), " is barrier!");
    }
    print_field.print(field);
}

void Controller::printPlayerInfo(Player &player) {
    std::cout << "Health: " << player.getHealth() << "\nProtection: " << player.getProtection() << "\nPoints: "
              << player.getPoints() << '\n';
}

void
Controller::getAction(bool &game, Player &player, Field *&field, IReader *reader, InputCommands *file_input, Log *&log,
                      IGameObserver *game_observer) {
    switch (reader->getDirection(file_input)) {
        case Direction::UP:
            try {
                Controller::movePlayerUp(*field, player);
            } catch (const PlayerMoveException &e) {
                field->getFieldObserver()->stepOnBarrier(std::string(e.what()));
            }
            break;
        case Direction::DOWN:
            try {
                Controller::movePlayerDown(*field, player);

            } catch (const PlayerMoveException &e) {
                field->getFieldObserver()->stepOnBarrier(std::string(e.what()));
            }
            break;
        case Direction::LEFT:
            try {
                Controller::movePlayerLeft(*field, player);
            } catch (const PlayerMoveException &e) {
                field->getFieldObserver()->stepOnBarrier(std::string(e.what()));
            }
            break;
        case Direction::RIGHT:
            try {
                Controller::movePlayerRight(*field, player);
            } catch (const PlayerMoveException &e) {
                field->getFieldObserver()->stepOnBarrier(std::string(e.what()));
            }
            break;
        case Direction::DOUBLE_UP:
            try {
                Controller::doubleMovePlayerUp(*field, player);
            } catch (const PlayerMoveException &e) {
                field->getFieldObserver()->stepOnBarrier(std::string(e.what()));
            }
            break;
        case Direction::DOUBLE_DOWN:
            try {
                Controller::doubleMovePlayerDown(*field, player);
            } catch (const PlayerMoveException &e) {
                field->getFieldObserver()->stepOnBarrier(std::string(e.what()));
            }
            break;
        case Direction::DOUBLE_LEFT:
            try {
                Controller::doubleMovePlayerLeft(*field, player);
            } catch (const PlayerMoveException &e) {
                field->getFieldObserver()->stepOnBarrier(std::string(e.what()));
            }
            break;
        case Direction::DOUBLE_RIGHT:
            try {
                Controller::doubleMovePlayerRight(*field, player);
            } catch (const PlayerMoveException &e) {
                field->getFieldObserver()->stepOnBarrier(std::string(e.what()));
            }
            break;
        case Direction::EXIT:
            game = false;
            break;
        case Direction::SAVE:
            Controller::saveGame(*field, player);
            game_observer->gameSaved(*log);
            break;
        case Direction::LOAD:
//            loadData(game_observer, log);
//            delete field;
//            delete log;
//            log = loadLog();
//            field = loadField(*log);
//            field->setObserver(*log);
//            loadPlayer(player);
//            player.setObserver(*log);
//            changeEventsObserver(field, log);
//            game_observer->gameLoaded(*log);
            load(player, field, log, game_observer);
            break;
        case Direction::NONE:
            break;
    }
    if (player.getDead() or player.getWin()) {
        game = false;
    }
}

bool Controller::isFileLogger(IReader *reader) {
    return reader->getIsFileLogger();
}

bool Controller::isConsoleLogger(IReader *reader) {
    return reader->getIsConsoleLogger();
}

int Controller::getFieldHeight(IReader *reader, IGameObserver *&game_observer, Log &log) {
    int field_height = 10;
    try {
        field_height = reader->getFieldHeight();
    } catch (const InputDataExeption &e) {
        game_observer->invalidInputData(log, std::string(e.what()));
    }
    return field_height;
}

int Controller::getFieldWidth(IReader *reader, IGameObserver *&game_observer, Log &log) {
    int field_width = 10;
    try {
        field_width = reader->getFieldWidth();
    } catch (const InputDataExeption &e) {
        game_observer->invalidInputData(log, std::string(e.what()));
    }
    return field_width;
}

bool Controller::isTraceLevel(IReader *reader) {
    return reader->getIsTraceLevel();
}

bool Controller::isInfoLevel(IReader *reader) {
    return reader->getIsInfoLevel();
}

bool Controller::isErrorLevel(IReader *reader) {
    return reader->getIsErrorLevel();
}

void Controller::printUserInfo() {
    std::cout << "Choose keys for commands. You should write them in file 'Commands.txt'. Keys should be unique!\n";
    std::cout << "Like this:\n";
    std::cout << "\tup-<key>\n"
                 "\tdown-<key>\n"
                 "\tleft-<key>\n"
                 "\tright-<key>\n"
                 "\tdouble up-<key>\n"
                 "\tdouble down-<key>\n"
                 "\tdouble left-<key>\n"
                 "\tdouble right-<key>\n"
                 "\texit-<key>\n"
                 "\tsave-<key>\n"
                 "\tload-<key>\n";
}

GameDifficulty Controller::getGameDifficulty(IReader *reader, IGameObserver *&game_observer, Log &log) {
    int difficulty = 1;
    try {
        difficulty = reader->getGameDifficulty();
    } catch (const InputDataExeption &e) {
        game_observer->invalidInputData(log, std::string(e.what()));
    }
    if (difficulty == 2)
        return GameDifficulty::MEDIUM;
    else
        return GameDifficulty::EASY;
}

int Controller::getCommand(IReader *reader) {
    int command = reader->getCommand();
    if (command < 1 or command > 3) {
        return 3;
    }
    return command;
}


void Controller::loadData(IGameObserver *&game_observer, Log *&log) {
    try {
        getIsFileValid();
    } catch (const SaveException &e) {
        if (log)
            game_observer->invalidFileForLoad(*log);
        throw SaveException("Game.txt", "Wrong data!");
    }
    data_for_load.clear();
    std::ifstream file_for_load = std::ifstream("Game.txt");
    std::string is_log_info;
    for (int k = 0; k < 5; k++) {
        file_for_load >> is_log_info;
        if (k == 0) {
            data_for_load.insert(std::make_pair("is_file_log", is_log_info));
        }
        if (k == 1)
            data_for_load.insert(std::make_pair("is_console_log", is_log_info));
        if (k == 2)
            data_for_load.insert(std::make_pair("is_trace_level", is_log_info));
        if (k == 3)
            data_for_load.insert(std::make_pair("is_info_level", is_log_info));
        if (k == 4)
            data_for_load.insert(std::make_pair("is_error_level", is_log_info));

    }
    int field_height;
    int field_width;
    int x_active_cell;
    int y_active_cell;
    int exit_x, exit_y;
    file_for_load >> field_height;
    data_for_load.insert(std::make_pair("field_height", std::to_string(field_height)));
    file_for_load >> field_width;
    data_for_load.insert(std::make_pair("field_width", std::to_string(field_width)));
    file_for_load >> x_active_cell;
    data_for_load.insert(std::make_pair("x_active_cell", std::to_string(x_active_cell)));
    file_for_load >> y_active_cell;
    data_for_load.insert(std::make_pair("y_active_cell", std::to_string(y_active_cell)));
    file_for_load >> exit_x;
    data_for_load.insert(std::make_pair("exit_x", std::to_string(exit_x)));
    file_for_load >> exit_y;
    data_for_load.insert(std::make_pair("exit_y", std::to_string(exit_y)));
    std::string cells;
    std::string line;
    for (int i = 0; i < field_height; i++) {
        file_for_load >> line;
        cells += line;
    }
    data_for_load.insert(std::make_pair("cells", cells));
    std::string player_points, player_protection, player_health, player_points_to_win;
    file_for_load >> player_points;
    file_for_load >> player_protection;
    file_for_load >> player_health;
    file_for_load >> player_points_to_win;
    data_for_load.insert(std::make_pair("player_points", player_points));
    data_for_load.insert(std::make_pair("player_protection", player_protection));
    data_for_load.insert(std::make_pair("player_health", player_health));
    data_for_load.insert(std::make_pair("player_points_to_win", player_points_to_win));
    file_for_load.close();
//    auto it1 = data_for_load.begin();
//    for (int i = 0; it1 != data_for_load.end(); it1++, i++) {  // выводим их
//        std::cout << i << ") key = " << it1->first << ", value = " << it1->second << std::endl;
//    }
//    system("pause");
}


void Controller::saveGame(Field &field, Player &player) {
    std::ofstream file_for_save;
    file_for_save.open("Game.txt", std::fstream::out | std::ofstream::trunc);
    if (!file_for_save.good()) {
        throw SaveException("Game.txt", "Cannot open save file!");
    }
    std::string data_str;
    if (field.getFieldObserver()->getLog().getIsFileLogger()) {
        file_for_save << "+\n";
        data_str += "+";
    } else {
        file_for_save << "-\n";
        data_str += "-";
    }
    if (field.getFieldObserver()->getLog().getIsConsoleLogger()) {
        file_for_save << "+\n";
        data_str += "+";
    } else {
        file_for_save << "-\n";
        data_str += "-";
    }
    if (field.getFieldObserver()->getLog().getIsTraceLevel()) {
        file_for_save << "+\n";
        data_str += "+";
    } else {
        file_for_save << "-\n";
        data_str += "-";
    }
    if (field.getFieldObserver()->getLog().getIsInfoLevel()) {
        file_for_save << "+\n";
        data_str += "+";
    } else {
        file_for_save << "-\n";
        data_str += "-";
    }
    if (field.getFieldObserver()->getLog().getIsErrorLevel()) {
        file_for_save << "+\n";
        data_str += "+";
    } else {
        file_for_save << "-\n";
        data_str += "-";
    }
    file_for_save << field.getHeight() << "\n";
    data_str += std::to_string(field.getHeight());
    file_for_save << field.getWidth() << "\n";
    data_str += std::to_string(field.getWidth());
    file_for_save << field.getActiveCellX() << "\n";
    data_str += std::to_string(field.getActiveCellX());
    file_for_save << field.getActiveCellY() << "\n";
    data_str += std::to_string(field.getActiveCellY());
    file_for_save << field.getExitX() << "\n";
    data_str += std::to_string(field.getExitX());
    file_for_save << field.getExitY() << "\n";
    data_str += std::to_string(field.getExitY());
    for (int i = 0; i < field.getHeight(); i++) {
        for (int j = 0; j < field.getWidth(); j++) {
            if (field.getCell(i, j).getActive()) {
                file_for_save << "a";
                data_str += "a";
            } else {
                if (field.getCell(i, j).getBarrier()) {
                    file_for_save << "b";
                    data_str += "b";
                } else {
                    if (!(field.getCell(i, j).getEvent())) {
                        file_for_save << "n";
                        data_str += "n";
                    }
                    if (dynamic_cast<Enemy *>(field.getCell(i, j).getEvent())) {
                        file_for_save << "e";
                        data_str += "e";
                    }
                    if (dynamic_cast<Money *>(field.getCell(i, j).getEvent())) {
                        file_for_save << "m";
                        data_str += "m";
                    }
                    if (dynamic_cast<Food *>(field.getCell(i, j).getEvent())) {
                        file_for_save << "f";
                        data_str += "f";
                    }
                    if (dynamic_cast<Trap *>(field.getCell(i, j).getEvent())) {
                        file_for_save << "t";
                        data_str += "t";
                    }
                    if (dynamic_cast<Exit *>(field.getCell(i, j).getEvent())) {
                        file_for_save << "x";
                        data_str += "x";
                    }
                }
            }
        }
        file_for_save << "\n";
    }
    file_for_save << player.getPoints() << "\n";
    data_str += std::to_string(player.getPoints());
    file_for_save << player.getProtection() << "\n";
    data_str += std::to_string(player.getProtection());
    file_for_save << player.getHealth() << "\n";
    data_str += std::to_string(player.getHealth());
    file_for_save << player.getPointsToWin() << "\n";
    data_str += std::to_string(player.getPointsToWin());
    std::ofstream file_for_hash = std::ofstream("Hash.txt");
    if (!file_for_hash.good()) {
        throw SaveException("Hash.txt", "Cannot open hash file!");
    }
    file_for_hash << hashing(data_str);
    file_for_hash.close();
    file_for_save.close();

}

long long Controller::hashing(const std::string &str) {
    const int k = 31, mod = 1e9 + 7;
    long long h = 0, m = 1;
    for (char c: str) {
        int x = (int) (c - 'a' + 1);
        h = (h + m * x) % mod;
        m = (m * k) % mod;
    }
    return h;
}

bool Controller::getIsFileValid() {
    std::string data_str = Controller::getDataStr();
    std::ifstream file_hash("Hash.txt");
    if (!file_hash.good()) {
        throw SaveException("Hash.txt", "Cannot open hash file!");
    }
    int hash = 0;
    file_hash >> hash;
    if (hash != Controller::hashing(data_str)) {
        throw SaveException("Game.txt", "Wrong data!");
        file_hash.close();
        return false;
    }
    file_hash.close();
    return true;
}

std::string Controller::getDataStr() {
    std::fstream file_for_load = std::fstream("Game.txt");
    if (!file_for_load.good()) {
        throw SaveException("Game.txt", "Cannot open save file!");
    }
    std::string line;
    std::string data_str;
    while (std::getline(file_for_load, line)) {
        data_str += line;
    }
    return data_str;
}

Field *Controller::loadField(Log &log) {
    int field_width, field_height, exit_x, exit_y;
    std::map<std::string, std::string>::iterator it;
    it = data_for_load.find("field_width");
    field_width = std::stoi(it->second);
    it = data_for_load.find("field_height");
    field_height = std::stoi(it->second);
    it = data_for_load.find("x_active_cell");
    int x_active = std::stoi(it->second);
    it = data_for_load.find("y_active_cell");
    int y_active = std::stoi(it->second);
    it = data_for_load.find("exit_x");
    exit_x = std::stoi(it->second);
    it = data_for_load.find("exit_y");
    exit_y = std::stoi(it->second);

    auto *field = new Field(field_height, field_width, x_active, y_active);
    field->changeExitPosition(exit_x, exit_y);

    it = data_for_load.find("cells");
    std::string cells = it->second;
    for (int i = 0; i < field_height; i++) {
        for (int j = 0; j < field_width; j++) {
            if (cells[i * field_width + j] == 'n') {
                continue;
            }
            if (cells[i * field_width + j] == 'b') {
                field->getCell(i, j).setBarrier();
            }
            if (cells[i * field_width + j] == 'e') {
                field->getCell(i, j).changeEvent(new Enemy(log));
            }
            if (cells[i * field_width + j] == 'a') {
                continue;
            }
            if (cells[i * field_width + j] == 't') {
                field->getCell(i, j).changeEvent(new Trap(log));
            }
            if (cells[i * field_width + j] == 'f') {
                field->getCell(i, j).changeEvent(new Food(log));
            }
            if (cells[i * field_width + j] == 'm') {
                field->getCell(i, j).changeEvent(new Money(log));
            }
            if (cells[i * field_width + j] == 'x') {
                field->getCell(i, j).changeEvent(new Exit(log));
            }
        }
    }
    return field;
}

Log *Controller::loadLog() {
    bool is_trace_level, is_info_level, is_error_level, is_file_logger, is_console_logger;
    std::map<std::string, std::string>::iterator it;
    it = data_for_load.find("is_trace_level");
    if (it->second == "+") {
        is_trace_level = true;
    } else {
        is_trace_level = false;
    }
    it = data_for_load.find("is_info_level");
    if (it->second == "+") {
        is_info_level = true;
    } else {
        is_info_level = false;
    }
    it = data_for_load.find("is_error_level");
    if (it->second == "+") {
        is_error_level = true;
    } else {
        is_error_level = false;
    }
    it = data_for_load.find("is_file_log");
    if (it->second == "+") {
        is_file_logger = true;
    } else {
        is_file_logger = false;
    }
    it = data_for_load.find("is_console_log");
    if (it->second == "+") {
        is_console_logger = true;
    } else {
        is_console_logger = false;
    }
    Log *log = new Log{is_trace_level, is_info_level, is_error_level, is_file_logger, is_console_logger};
    return log;
}

void Controller::loadPlayer(Player &player) {
    int player_points, player_protection, player_health, player_points_to_win;
    std::map<std::string, std::string>::iterator it;
    it = data_for_load.find("player_points");
    player_points = std::stoi(it->second);
    it = data_for_load.find("player_protection");
    player_protection = std::stoi(it->second);
    it = data_for_load.find("player_health");
    player_health = std::stoi(it->second);
    it = data_for_load.find("player_points_to_win");
    player_points_to_win = std::stoi(it->second);
    player.setHealth(player_health);
    player.setProtection(player_protection);
    player.setPoints(player_points);
    player.setPointsToWin(player_points_to_win);
}

void Controller::setFileInputObserver(Log *log, InputCommands *file_input) {
    file_input->setObserver(*log);
}

void Controller::setFieldObserver(Field *field, Log *log) {
    field->setObserver(*log);
}

void Controller::setPlayerObserver(Player &player, Log *log) {
    player.setObserver(*log);
}

void Controller::changeEventsObserver(Field *field, Log *log) {
    for (int i = 0; i < field->getHeight(); i++) {
        for (int j = 0; j < field->getWidth(); j++) {
            if (field->getCell(i, j).getEvent())
                field->getCell(i, j).getEvent()->changeObserver(log);
        }
    }
}

void Controller::load(Player &player, Field *&field, Log *&log, IGameObserver *game_observer) {
    try {
        loadData(game_observer, log);
    } catch (const SaveException &e){
        return;
    }
    loadData(game_observer, log);
    delete field;
    delete log;
    log = loadLog();
    field = loadField(*log);
    field->setObserver(*log);
    loadPlayer(player);
    player.setObserver(*log);
    changeEventsObserver(field, log);
    game_observer->gameLoaded(*log);
}


SaveException::SaveException(std::string filename, std::string what) noexcept
        : _filename(std::move(filename)), _what(std::move(what)),
          _out("(" + _filename + ") " + _what) {}

const char *SaveException::what() const noexcept {
    return _out.data();
}

PlayerMoveException::PlayerMoveException(int x, int y, std::string what) noexcept
        : _x(x), _y(y), _what(std::move(what)),
          _out(" Cell[" + std::to_string(x) + "][" + std::to_string(y) + "]" + _what) {}

const char *PlayerMoveException::what() const noexcept {
    return _out.data();
}

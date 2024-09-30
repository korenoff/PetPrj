
#ifndef OOP_LAB1_CONTROLLER_H
#define OOP_LAB1_CONTROLLER_H

#include "Objects/Field.h"
#include "View/PrintField.h"
#include "Readers/ConsoleCommandReader.h"
#include "Log/Log.h"
#include "Log/Observers/IGameObserver.h"

class SaveException : public std::exception {
public:
    explicit SaveException(std::string filename, std::string what) noexcept;
    [[nodiscard]] const char* what() const noexcept override;

private:
    std::string _filename;
    std::string _what;
    std::string _out;
};

class PlayerMoveException : public std::exception {
public:
    explicit PlayerMoveException(int x, int y, std::string what) noexcept;
    [[nodiscard]] const char* what() const noexcept override;

private:
    int _x, _y;
    std::string _what;
    std::string _out;
};

class Controller {
private:
    std::map<std::string, std::string> data_for_load;
public:
    int getFieldHeight(IReader *reader, IGameObserver *&game_observer, Log &log);
    int getFieldWidth(IReader *reader, IGameObserver *&game_observer, Log &log);
    bool isTraceLevel(IReader *reader);
    bool isInfoLevel(IReader *reader);
    bool isErrorLevel(IReader *reader);
    bool isFileLogger(IReader *reader);
    bool isConsoleLogger(IReader *reader);

    void movePlayerUp(Field& field, Player& player);
    void movePlayerDown(Field &field, Player& player);
    void movePlayerRight(Field &field, Player& player);
    void movePlayerLeft(Field &field, Player& player);

    void doubleMovePlayerUp(Field& field, Player& player);
    void doubleMovePlayerDown(Field& field, Player& player);
    void doubleMovePlayerRight(Field& field, Player& player);
    void doubleMovePlayerLeft(Field& field, Player& player);
    void setFileInputObserver(Log *log, InputCommands *file_input);
    void setFieldObserver(Field *field, Log *log);
    void setPlayerObserver(Player &player, Log *log);
    void changeEventsObserver(Field *field, Log *log);

    void saveGame(Field& field, Player& player);
    long long hashing(const std::string& str);
    std::string getDataStr();
    bool getIsFileValid();
    void load(Player &player, Field *&field, Log *&log, IGameObserver *game_observer);

    void getAction(bool &game, Player &player, Field *&field, IReader *reader, InputCommands *file_input, Log *&log, IGameObserver *game_observer);
    void printPlayerInfo(Player &player);
    void printUserInfo();
    int getCommand(IReader *reader);
    GameDifficulty getGameDifficulty(IReader *reader, IGameObserver *&game_observer, Log &log);


    void loadPlayer(Player &player);

    Log *loadLog();

    Field *loadField(Log &log);

    void loadData(IGameObserver *&game_observer, Log *&log);
};


#endif //OOP_LAB1_CONTROLLER_H

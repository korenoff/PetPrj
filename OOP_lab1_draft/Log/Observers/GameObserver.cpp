
#include "GameObserver.h"

void GameObserver::gameStarted(Log &log) {
    Message message = Message("[GAME INFO] Game started", Level::INFO);
    log.viewMessage(message);
}

void GameObserver::gameEnded(Log &log) {
    Message message = Message("[GAME INFO] Game ended", Level::INFO);
    log.viewMessage(message);
}

void GameObserver::gameSaved(Log &log) {
    Message message = Message("[INFO] Game saved", Level::INFO);
    log.viewMessage(message);
}

void GameObserver::gameLoaded(Log &log) {
    Message message = Message("[INFO] Game loaded", Level::INFO);
    log.viewMessage(message);
}

void GameObserver::invalidInputData(Log &log, std::basic_string<char> mes) {
    std::string str_mes = "[ERROR] " + mes;
    Message message = Message(str_mes, Level::ERROR_INFO);
    log.viewMessage(message);
}

void GameObserver::invalidFileForLoad(Log &log) {
    Message message = Message("[ERROR] Something wrong with file \"Game.txt\"!", Level::ERROR_INFO);
    log.viewMessage(message);
}

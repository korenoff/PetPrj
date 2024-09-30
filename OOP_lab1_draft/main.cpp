#include <iostream>
#include "Events/Event.h"
#include "Objects/Cell.h"
#include "Objects/Player.h"
#include "Objects/Field.h"
#include "View/PrintField.h"
#include "Controller.h"
#include "Readers/ConsoleCommandReader.h"
#include "Factory/Factory.h"
#include "Application.h"


int main() {
    Application application;
    application.start();
    return 0;
}

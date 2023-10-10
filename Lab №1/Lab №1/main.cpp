#include <iostream>
#include "TApplication.h"

int main() {
    setlocale(LC_ALL, "");
    TApplication Application;
    Application.Executor();

    return 1;
}
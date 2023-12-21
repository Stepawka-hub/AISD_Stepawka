#include <iostream>
#include "TApplication.h"

int main() {
    setlocale(LC_ALL, "");
    TApplication App;
    App.Executor();

    return 0;
}
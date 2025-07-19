# Logger Project

## Описание

Консольная многопоточная программа и библиотека на C++17, позволяющая логировать сообщения в файл или сокет с уровнями важности (INFO, WARNING, ERROR).

## Запуск

```bash
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/app/logger_app logs.txt INFO

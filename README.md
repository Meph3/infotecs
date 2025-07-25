# Logger Project

## Описание

Многофункциональная C++-библиотека логирования с поддержкой:
- логирования в файл и через TCP-сокет,
- выбора уровня логирования (`INFO`, `WARNING`, `ERROR`),
- статической и динамической сборки,
- юнит-тестов,
- консольной программы для мониторинга логов по сокету.

> Флаг `BUILD_SHARED_LIBS` переключает между статической и динамической версией библиотеки `logger`.

## Команды 

```bash
# 1. Сборка (по умолчанию статическая)
cmake -B build -S .
cmake --build build

# 2. Сборка с динамической библиотекой
cmake -B build -S . -DBUILD_SHARED_LIBS=ON
cmake --build build

# 3. Запуск тестов
./build/logger_tests

# 4. Логирование в файл
./build/app/logger_app logs.txt INFO

# 5. Логирование по сокету
./build/app/logger_app 127.0.0.1:5000 INFO

# 6. Мониторинг логов (на другом терминале)
./build/monitor/logger_monitor 5000 5 10





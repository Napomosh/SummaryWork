Для выполнения действий необходимо находиться в директории Summary.


Для работы программы необходима библиотека nlohman. Если ее нет, можно установить с помощью sudo apt-get install nlohmann-json3-dev

Для работы программы необходима библиотека doctest. Если ее нет, можно установить с помощью sudo apt-get install doctest-dev

Так же для установки всех зависимостей можно запустить ./scripts/submodules.sh


Для сборки проекта можно запустить ./scripts/build.sh или ./scripts/build_and_run.sh (соберет и сразу запустит)

Для запуска можно прописать ./scripts/run.sh Программа использует аргументы командной строки. Этот скрипт возьмет правила и один из отчетов из директории resources.
Для выполнения программы для своих отчетов необходимо запустить программу вручную:

1) Переходим в директорию build
2) запускаем main и передаем параметры -r <имя файла с правилами> -l <имя файла с отчетом> -s <имя имя файла с исходным кодом>
3) Например, ./main -l /home/alex/CLionProjects/SummaryWork/Summary/resources/lab19.pdf -r /home/alex/CLionProjects/SummaryWork/Summary/resources/json_file.json  -s /home/alex/CLionProjects/SummaryWork/Summary/src/Settings.cpp (пути будут другие)


Если скрипты выдают ошибку: bash: ./scripts/<script_name>.sh: Permission denied, то разрешаем полный доступ к скриптам командой chmod 777 -R scripts

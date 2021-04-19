Для выполнения действий необходимо находиться в директории Summary.

Для работы программы необходима библиотека nlohman. Если ее нет, можно установить с помощью sudo apt-get install nlohmann-json3-dev или ./scripts/submodules.sh

Для сборки проекта можно запустить ./scripts/build.sh или ./scripts/build_and_run.sh (соберет и сразу запустит)

Для запуска можно прописать ./scripts/run.sh

Если скрипты выдают ошибку: bash: ./scripts/<script_name>.sh: Permission denied, то разрешаем полный доступ к скриптам командой chmod 777 -R scripts

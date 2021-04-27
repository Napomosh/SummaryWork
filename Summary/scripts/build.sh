if [ -d "build" ]; 
then
	rm -rf build/*
else
        mkdir -p build
fi   
cmake -S ../Summary -B build
cd build
make

CXX  = g++

all:
	cd systeminfo && $(MAKE) -e CXX='${CXX}'
	cd dlltest/src && $(MAKE) -e CXX='${CXX}'
	cd SqliteTest && $(MAKE) -e CXX='${CXX}'
	cd RSATest && $(MAKE) -e CXX='${CXX}'
	
clean:
	cd systeminfo && $(MAKE) clean
	cd dlltest/src && $(MAKE) clean
	cd SqliteTest && $(MAKE) clean
	cd RSATest && $(MAKE) clean
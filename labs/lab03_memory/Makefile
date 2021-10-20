CXX=g++
CXXFLAGS = -std=c++11 -g
ROOT_DIR := $(shell git rev-parse --show-toplevel)
-include $(ROOT_DIR)/config/settings
-include $(DEP_DIR)/env

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

%_app: %.o
	$(CXX) $(CXXFLAGS) $< -o $@ 

all: image_app memory_app

# TODO: Add Applicaiton Targets

# TODO: Add Object File Targets

clean:
	rm -f *.o *_app


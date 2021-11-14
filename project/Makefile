CXX=g++
CXXFLAGS = -std=c++11 -g
ROOT_DIR := $(shell git rev-parse --show-toplevel)
-include $(ROOT_DIR)/config/settings
-include $(DEP_DIR)/env

BUILD_DIR = build
INCLUDES = -I.. -I$(DEP_DIR)/include -Isrc -I. -I$(DEP_DIR)/include -Iinclude -I.
LIBDIRS = -L$(DEP_DIR)/lib 
LIBS = -lCppWebServer -lwebsockets -lssl -lcrypto -lz -lpthread

SOURCES = $(wildcard *.cc) $(wildcard src/*.cc) $(wildcard src/*/*.cc)
OBJFILES = $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES:.cc=.o)))

EXEFILE = $(BUILD_DIR)/web-app

TESTFILES = $(wildcard tests/*.cc)
TESTOBJFILES = $(filter-out $(BUILD_DIR)/main.o,$(OBJFILES)) $(addprefix $(BUILD_DIR)/, $(notdir $(TESTFILES:.cc=.o)))
TESTEXEFILE = $(BUILD_DIR)/test-app

all: $(BUILD_DIR) $(EXEFILE) tests

tests: $(BUILD_DIR) $(TESTEXEFILE)

# Applicaiton Targets:
$(EXEFILE): $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(LIBDIRS) $(OBJFILES) $(LIBS) -o $@

# Object File Targets:
$(BUILD_DIR)/%.o: src/%.cc 
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Generate dependencies
make-depend-cxx=$(CXX) -MM -MF $3 -MP -MT $2 $(CXXFLAGS) $(INCLUDES) $1
-include $(OBJFILES:.o=.d)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TESTEXEFILE): $(TESTOBJFILES)
	$(CXX) $(CXXFLAGS) $(LIBDIRS) $(TESTOBJFILES) -lgtest_main -lgtest -lgmock $(LIBS) -o $@

# Object File Targets:
$(BUILD_DIR)/%.o: tests/%.cc 
	$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf build


TARGET_EXEC := zkProver

BUILD_DIR := ./build
SRC_DIRS := ./src

LIBOMP := $(shell find /usr/lib/llvm-* -name "libomp.so" | sed 's/libomp.so//')
ifndef LIBOMP
$(error LIBOMP is not set, you need to install libomp-dev)
endif

CXX := g++
AS := nasm
CXXFLAGS := -std=c++17 -Wall -pthread
LDFLAGS :=  -L/home/fractasy/git/grpc/libs/opt -L/home/fractasy/git/grpc/cmake/build/third_party/protobuf -L/home/fractasy/git/grpc/cmake/build -lprotobuf -lsodium -lgrpc -lgrpc++ -lgrpc++_reflection -lgpr -lgrpc_unsecure -lpthread -lpqxx -lpq -lgmp -lstdc++ -lomp -lgmpxx -lsecp256k1 -L$(LIBOMP)
CFLAGS := -fopenmp -D'memset_s(W,WL,V,OL)=memset(W,V,OL)'
ASFLAGS := -felf64 

# Debug build flags
ifeq ($(dbg),1)
      CXXFLAGS += -g
else
      CXXFLAGS += -O3
endif

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.asm -or -name *.cc)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP


$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# assembly
$(BUILD_DIR)/%.asm.o: %.asm
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CFLAGS) -I~/git/grpc/include -I~/git/grpc/third_party/abseil-cpp -I~/git/grpc/third_party/protobuf/src -I~/git/rapidsnark/depends/ffiasm/c -I~/git/rapidsnark/src $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.cc.o: %.cc
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CFLAGS) -I/home/fractasy/git/grpc/include -I/home/fractasy/git/grpc/third_party/abseil-cpp -I/home/fractasy/git/grpc/third_party/protobuf/src $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
ROOT=$(abspath .)
VERSION=v1.39.0

BUILD=build
URL=https://github.com/libuv/libuv

all: $(BUILD)

$(BUILD):
	[ -d $(BUILD) ] || mkdir -p $(BUILD)
	git clone $(URL) --branch $(VERSION) $(BUILD)
	cd $(BUILD) && \
	sh ./autogen.sh && \
	./configure && \
	make

clean:
	rm -rf $(BUILD)
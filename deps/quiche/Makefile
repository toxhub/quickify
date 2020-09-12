ROOT=$(abspath .)
VERSION=0.5.1

VERSION_DIR="$(ROOT)/build/$(VERSION)"
BUILD="$(VERSION_DIR)/quiche-$(VERSION)"
URL=https://github.com/cloudflare/quiche

all: $(BUILD)

$(BUILD):
	[ -d $(BUILD) ] || mkdir -p $(VERSION_DIR)
	git clone --recursive $(URL) --branch $(VERSION) $(BUILD)
	cd $(BUILD)
	cargo build --release --features pkg-config-meta,qlog
	mkdir deps/boringssl/src/lib
	ln -vnf $(find target/release -name libcrypto.a -o -name libssl.a) deps/boringssl/src/lib/

clean:
	rm -rf $(BUILD)
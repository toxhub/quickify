ROOT=$(abspath .)
VERSION=0.5.1

BUILD=build
URL=https://github.com/cloudflare/quiche

all: $(BUILD)

$(BUILD):
	[ -d $(BUILD) ] || mkdir -p $(BUILD)
	git clone --recursive $(URL) --branch $(VERSION) $(BUILD)
	cd $(BUILD) && \
	cargo build --release --features pkg-config-meta,qlog && \
	mkdir deps/boringssl/src/lib && \
	ln -vnf $(find target/release -name libcrypto.a -o -name libssl.a) deps/boringssl/src/lib/

clean:
	rm -rf $(BUILD)
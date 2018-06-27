
# Build source codes to make it kernel module along with kernel specified by -C
make -C /usr/src/linux-headers-4.15.0-23-generic SUBDIRS=$PWD modules

# Create signing key
#openssl req -new -x509 -newkey rsa:2048 -keyout MOK.priv -outform DER -out MOK.der -nodes -days 36500 -subj "/CN=Descriptive name/"

# Sign the module
#sudo /usr/src/linux-headers-$(uname -r)/scripts/sign-file sha256 ./MOK.priv ./MOK.der ./my_mod.ko

# Register the keys to secure boot
#sudo mokutil --import MOK.der


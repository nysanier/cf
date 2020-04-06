# configure
mkdir cbuild_actions
cd cbuild_actions
cmake .. -DCMAKE_BUILD_TYPE=Debug

# make
make test_abbr

# make check
test/test_abbr

exit 1


set -e

# 定义 GOPATH
abspath=$(cd "$(dirname "$0")"; pwd)
pkgpath="$abspath/../../../golang"
export GOPATH=$pkgpath:$abspath

# 编译
ut="C"
if (( $# >= 1 )); then  # 参数个数, 会忽略掉命令本身的1个
    ut="$1"
fi

echo "running $ut ..."
cd "src/$ut"
go run -v .

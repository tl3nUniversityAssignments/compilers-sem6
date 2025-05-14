FROM ubuntu:16.04

RUN apt update && \
    apt install -y wget gnupg software-properties-common && \
    wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - && \
    add-apt-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-3.9 main" && \
    apt update && \
    apt install -y clang-3.9 build-essential

WORKDIR /workspace
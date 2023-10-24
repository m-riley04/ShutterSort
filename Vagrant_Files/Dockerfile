# Start your image with a node base image

FROM ubuntu:latest

LABEL Description="Build environment"

ENV HOME /root

SHELL ["/bin/bash", "-c"]

RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    gcc \
    g++ \
    cmake \
    gdb \
    wget \
    git \
    curl \
    libboost-all-dev \
    libboost-thread-dev \
    libboost-dev \
    libstdc++6 \
    perl \
    python3 \
    exiv2 \ 
    qt6-base-dev

RUN apt-get update && apt-get -y --no-install-recommends install \
    '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev libxkbcommon-dev libxkbcommon-x11-dev

RUN cd ${HOME} && \
    wget --no-check-certificate --quiet \
        https://boostorg.jfrog.io/artifactory/main/release/1.77.0/source/boost_1_77_0.tar.gz && \
        tar xzf ./boost_1_77_0.tar.gz && \
        cd ./boost_1_77_0 && \
        ./bootstrap.sh && \
        ./b2 install && \
        cd .. && \
        rm -rf ./boost_1_77_0

RUN curl -fsSL https://code-server.dev/install.sh | sh

RUN apt update && apt install  openssh-server sudo -y

RUN useradd -rm -d /home/ubuntu -s /bin/bash -g root -G sudo -u 1000 test 

RUN  echo 'root:root' | chpasswd

RUN service ssh start

EXPOSE 22

CMD ["/usr/sbin/sshd", "-D"]
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
    libexiv2-dev \ 
    qt6-base-dev

RUN apt-get update && apt-get -y --no-install-recommends install \
    '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev libxkbcommon-dev libxkbcommon-x11-dev

RUN curl -fsSL https://code-server.dev/install.sh | sh

RUN apt update && apt install  openssh-server sudo -y

RUN useradd -rm -d /home/ubuntu -s /bin/bash -g root -G sudo -u 1000 test 

RUN  echo 'root:root' | chpasswd

RUN service ssh start

EXPOSE 22

CMD ["/usr/sbin/sshd", "-D"]
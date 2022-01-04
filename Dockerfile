FROM devkitpro/devkitppc@sha256:b4c7622442bef192fa13ef34ec90741820cef2fb0c6d6b317a9bd55da06cfa60
RUN dkp-pacman -Syyu --noconfirm && dkp-pacman -Scc --noconfirm
RUN git clone https://github.com/wiiu-env/libiosuhax.git && cd libiosuhax && make install && cd .. && rm -rf libiosuhax

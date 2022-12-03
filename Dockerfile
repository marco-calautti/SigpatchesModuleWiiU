FROM devkitpro/devkitppc@sha256:b4c7622442bef192fa13ef34ec90741820cef2fb0c6d6b317a9bd55da06cfa60
ENV PATH=$DEVKITPPC/bin:$PATH \
 WUT_ROOT=$DEVKITPRO/wut
RUN dkp-pacman -Syyu --noconfirm && dkp-pacman -Scc --noconfirm
COPY --from=wiiuenv/libmocha:20220919112600f3c45c /artifacts $DEVKITPRO
WORKDIR /project

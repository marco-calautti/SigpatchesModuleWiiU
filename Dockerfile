FROM wiiuenv/devkitppc:20220917 AS final
RUN git clone https://github.com/wiiu-env/libiosuhax.git && cd libiosuhax && make install && cd .. && rm -rf libiosuhax

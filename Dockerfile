FROM gcc:13 AS build
WORKDIR /src
COPY lab2.cpp .
RUN g++ -std=c++17 -O2 -Wall -Wextra -static -o lab2 lab2.cpp

FROM debian:bookworm-slim
WORKDIR /app
COPY --from=build /src/lab2 .
CMD ["./lab2"]

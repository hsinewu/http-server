all:
	make -C ./src

install:
	cp ./systemd/service.sh /usr/bin/http
	cp ./systemd/http.service /etc/systemd/system/http.service

clean:
	rm http build/*

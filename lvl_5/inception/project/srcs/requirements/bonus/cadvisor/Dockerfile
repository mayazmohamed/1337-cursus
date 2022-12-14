FROM alpine:3.17

RUN apk update && apk upgrade
RUN apk add --no-cache curl
RUN curl -L https://github.com/google/cadvisor/releases/download/v0.37.5/cadvisor -o /usr/bin/cadvisor
RUN chmod +x /usr/bin/cadvisor
EXPOSE 2000

CMD ["cadvisor", "logtostderr"]
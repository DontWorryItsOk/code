FROM node:14
WORKDIR /home/DOCKERdz
COPY package*.json ./
COPY index.html .
RUN npm install
EXPOSE 80
CMD [ "npm", "start" ]
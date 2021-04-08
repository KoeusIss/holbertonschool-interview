#!/usr/bin/node
const request = require('request');

const film = process.argv[2];
const baseUrl = `https://swapi-api.hbtn.io/api/films/${film}`;

request(baseUrl, async (error, response, body) => {
  if (!error) {
    const characters = JSON.parse(body).characters;
    for (const character in characters) {
      await new Promise((resolve, reject) => {
        request(characters[character], (error, response, body) => {
          if (!error) {
            console.log(JSON.parse(body).name);
            resolve();
          }
        });
      });
    }
  }
});

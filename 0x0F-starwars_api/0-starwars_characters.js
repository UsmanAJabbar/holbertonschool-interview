#!/usr/bin/node
// Returns the cast from the Star Wars movie
const request = require('request');

const end = 'https://swapi-api.hbtn.io/api/films/';
const filmNo = process.argv[2];

request(`${end + filmNo}`, (error, response, body) => {
  if (!error && response.statusCode === 200) {
    const data = JSON.parse(body);
    for (const characterEndpoint of data.characters) {
      request(characterEndpoint, (error, response, body) => {
        if (!error && response.statusCode === 200) {
          const character = JSON.parse(body);
          console.log(character.name);
        }
      });
    }
  }
});

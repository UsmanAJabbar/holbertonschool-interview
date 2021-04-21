#!/usr/bin/node
// Returns the cast from the Star Wars movie
const request = require('request');
const filmNo = process.argv[2];

const character_print = (character_api_urls, index) => {
  if (character_api_urls[index]) {
    request.get(character_api_urls[index], (error, response, body) => {
      const character_name = JSON.parse(body).name;
      console.log(character_name);
      character_print(character_api_urls, index + 1);
    })
  }
}

request.get(`https://swapi-api.hbtn.io/api/films/${filmNo}`, (error, response, body) => {
  if (!error && response.statusCode === 200) {
    const data = JSON.parse(body).characters;
    character_print(data, 0);
  }
});
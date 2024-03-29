#!/usr/bin/node
// Returns the cast from the Star Wars movie
const request = require('request');
const filmNo = process.argv[2];

const characterNamePrint = (characterAPIurls, index) => {
  if (characterAPIurls[index]) {
    request.get(characterAPIurls[index], (error, response, body) => {
      if (!error && response.statusCode === 200) {
        const characterName = JSON.parse(body).name;
        console.log(characterName);
        characterNamePrint(characterAPIurls, index + 1);
      }
    });
  }
};

request.get(`https://swapi-api.hbtn.io/api/films/${filmNo}`, (error, response, body) => {
  if (!error && response.statusCode === 200) {
    const data = JSON.parse(body).characters;
    characterNamePrint(data, 0);
  }
});

const fs = require('fs');
const path = require('path');
const crypto = require('crypto');

function sha256(data) {
    return crypto.createHash('sha256').update(data).digest('hex');
}

// Read in the file given on the command line
var file = process.argv[2];
var contents = fs.readFileSync(file, 'utf8');
var frozen = JSON.parse(contents);

// all the other files on the command line
var files = process.argv.slice(3);

// foreach file
files.forEach(function (file) {

    // if file already in hash
    var found = frozen.find(f => f.file === file)
    if(found) {
        console.log(`File ${file} already frozen`);
        console.log("Replacing with new hash");
        // remove from frozen
        var index = frozen.indexOf(found);
        frozen.splice(index, 1);
    }

    var sha = sha256(fs.readFileSync(file));
    console.log(`Adding ${file} ${sha} to the frozen list`);
    frozen.push({
        file: file,
        sha256: sha
    })
});

fs.writeFileSync(file, JSON.stringify(frozen, null, 2));
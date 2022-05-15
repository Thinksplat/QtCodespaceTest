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

var fail = false;
frozen.forEach(function (obj) {
    var file = obj.file;
    try {
        var filecontents = fs.readFileSync(file);
    }
    catch (err) {
        console.log("File not found: " + file);
        fail = true;
        return;
    }
    var hash = sha256(filecontents);
    if (hash !== obj.sha256) {
        console.log("Frozen file " + file + " has been modified.");
        fail = true;
    }
});

if (fail) {
    process.exit(1);
}
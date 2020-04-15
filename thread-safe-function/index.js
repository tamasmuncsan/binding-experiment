const { createTSFN } = require('bindings')('addon');

const callback = (...args) => { 
    console.log(new Date, ...args); 
};

console.log('This happens first!');
createTSFN(callback);
console.log('This happens second(?) - because we\'re async!');

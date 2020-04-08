const { NativeAddon } = require('bindings')('addon')
const { add } = require('mathjs');

const addon = new NativeAddon();

addon.RunCallback(() => {
    console.log('This call works!');
});

try {
    addon.RunCallback();
} catch (error){
    console.log('This call wont work because we didnt add an argument');
    console.trace(error);
}

try {
    addon.RunCallback('this is a string argument, which should be a function');
} catch (error){
    console.log('This call wont work because we didnt add a function argument');
    console.trace(error);
}

const result = addon.RunMathCallback(add, 1, 2);
console.log(`1 + 2 = ${result}`);

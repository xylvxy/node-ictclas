/**
 * @license
 * Node-polling 0.0.1 <http://github.com/xylvxy/node-polling>
 * Copyright (c) 2013-2014 James Loo
 * Available under MIT license
 */
(function(){
try {
	// Load the precompiled win32 binary
	if(process.platform == "win32" && process.arch == "x64") {
        process.env.PATH+=';'+__dirname+'/ext/lib/win64/';
    }else if(process.platform == "win32" && process.arch == "ia32") {
        process.env.PATH+=';'+__dirname+'/ext/lib/win32/';
	} else if(process.platform == "linux"&& process.arch == "x64") {
        process.env+=';'+__dirname+'/ext/lib/linux64/';
    } else if(process.platform == "linux"&& process.arch == "ia32") {
        process.env+=';'+__dirname+'/ext/lib/linux32/';
	} else {
        throw('not support platform');
	}	
} catch(err) {
    consoel.log(err);
    process.exit();
}
var ICT = require('./build/Release/ictclas');
exports.init = function(path){
    path = path || __dirname+'/ext/';
    ICT.init(path);
    return ICT;
};
})();
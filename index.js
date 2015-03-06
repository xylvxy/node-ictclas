/**
 * @license
 * Node-polling 0.0.1 <http://github.com/xylvxy/node-polling>
 * Copyright (c) 2013-2014 James Loo
 * Available under MIT license
 */
(function(){
    var ICT = require('./build/Release/ictclas');
    exports.init = function(path){
        path = path || __dirname+'/ext/'
        ICT.init(path);
        return ICT;
    };
})();
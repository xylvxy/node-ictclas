
{
  'targets': [
	{
      'target_name': 'ictclas',
      'sources': [ './ext/ictclas.cc' ],
      'link_settings': {
        'libraries': [
          '-lNLPIR'
        ]},
        'conditions': [
          ['OS=="linux"', {
            'library_dirs': [
              './ext/lib/linux64'
            ]
            }
          ],
          ['OS=="win"', {
            'library_dirs': [
              './ext/lib/win64'
            ]
            }
          ]]
      }]
}

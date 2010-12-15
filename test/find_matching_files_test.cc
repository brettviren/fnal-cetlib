#include "cetlib/find_matching_files.h"

#include "cetlib/search_path.h"
#include <iostream>
#include <iterator>  // back_inserter, ostream_iterator
#include <string>
#include <vector>

using cet::find_matching_files;

typedef std::vector<std::string> strings_t;

/*
  example regular expression = "^lib([A-Za-z0-9_]+)_plugin.so$"

  This program needs to be driven by a shell script to make
  management of files easier, such as creating and destroying
  temporary directories and files.
*/

int
  main( int argc, char * argv[] )
{
  if( argc < 3 ) {
    std::cerr << "usage: " << argv[0] << " regex_pattern directory_name\n";
    return -1;
  }

  strings_t results;
  std::size_t count = find_matching_files( argv[1]
                                         , argv[2]
                                         , std::back_inserter(results)
                                         );

  std::copy( results.begin(), results.end()
           , std::ostream_iterator<std::string>(std::cout,"\n")
           );

  return count;
}

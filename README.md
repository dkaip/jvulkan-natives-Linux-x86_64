# jvulkan-natives-Linux-x86_64

jvulkan-natives-Linux-x86_64 is a native library written in c++ that is used (required) by the 
jvulkan (Java Vulkan SDK project).

## Building
From the root directory,

For a debug version:

mkdir Debug<br/>
cd Debug<br/>
cmake -DCMAKE_BUILD_TYPE=Debug ..<br/>
make -j32 (You may leave out the -j option it just tells make how many cores it may use.)<br/>

For a release version:

mkdir Release<br/>
cd Release<br/>
cmake -DCMAKE_BUILD_TYPE=Release ..<br/>
make -j32 (You may leave out the -j option it just tells make how many cores it may use.)<br/>



## Installation

Use the package manager [pip](https://pip.pypa.io/en/stable/) to install foobar.

```bash
pip install foobar
```

## Usage

```python
import foobar

foobar.pluralize('word') # returns 'words'
foobar.pluralize('goose') # returns 'geese'
foobar.singularize('phenomena') # returns 'phenomenon'
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[Apache 2.0](http://www.apache.org/licenses/LICENSE-2.0)
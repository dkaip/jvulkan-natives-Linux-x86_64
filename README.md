# jvulkan-natives-Linux-x86_64

jvulkan-natives-Linux-x86_64 is a native library written in c++ that is used (required) by the 
jvulkan (Java Vulkan SDK project).

## Building
<code>cd</code> to the root directory.<br/>
Edit the <code>CMakeLists.txt</code> file.<br/>
Alter the second arguments of the <code>set</code> statements that are 
before the <code>project</code> statement and replace the values that are 
currently there with values that are appropriate for your system / development 
environment.
<p>
Just as a side note, I was not able to debug the native code with a debugger while 
developing it.  Possibly since this code's job is to interface between code written
in Java and the libraries provided in the LunarG Vulkan SDK. I had to debug the old fashioned way with print statements (<code>cout</code>).

To produce a debug version:

mkdir Debug<br/>
cd Debug<br/>
cmake -DCMAKE_BUILD_TYPE=Debug ..<br/>
make -j32 (You may leave out the -j option it just tells make how many cores it may use.)<br/>

To produce a release version:

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
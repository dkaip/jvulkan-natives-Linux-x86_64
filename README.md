# jvulkan-natives-Linux-x86_64

**jvulkan-natives-Linux-x86_64** is a native library written in c++ that is used (required) by the 
**jvulkan** (Java Vulkan SDK) project.  This project provides the interface between **jvulkan** 
and the [Vulkan® SDK](https://www.lunarg.com/vulkan-sdk/) from LUNARG which is written in c++.

## Prerequisites
You will need the [Vulkan® SDK](https://www.lunarg.com/vulkan-sdk/) from LUNARG.  You will 
need to download and build it.  If possible get the version <code>1.1.101.0</code>.  Later 
**might** work as well.

You will also need the Wayland development code.  It may be in the package 
<code>wayland-devel.x86\_64</code> and / or perhaps <code>libwayland-client.x86\_64</code>. 
Additionally you may just be able to download it from [freedesktop.org](https://wayland.freedesktop.org/).

## Get the code
Use the <code>git clone</code> command to get the code. 

<code>git clone path-to-repository jvulkan-natives-Linux-x86_64</code> 

This will create a <code>jvulkan-natives-Linux-x86_64</code> directory in your current directory


## Building
Change your current directory (<code>cd</code>) to the project root directory.  If you used the 
command above it would be <code>cd jvulkan-natives-Linux-x86_64.</code>  

Edit the <code>CMakeLists.txt</code> file.</br>
Alter the second arguments of the <code>set</code> statements that are 
before the <code>project</code> statement and replace the values that are 
currently there with values that are appropriate for your system / development 
environment.
<p>
Just as a side note, I was not able to debug the native code with a debugger while 
developing it.  Possibly since this code's job is to interface between code written
in Java and the libraries provided in the LunarG Vulkan SDK. I had to debug the old fashioned way with print statements (<code>cout</code>).

To produce a debug version:

<code>
mkdir Debug </br>
cd Debug </br>
cmake -DCMAKE_BUILD_TYPE=Debug .. </br>
make -j32 (You may leave out the -j option it just tells make how many cores it may use.) </code>

To produce a release version:

<code>
mkdir Release</br>
cd Release</br>
cmake -DCMAKE_BUILD_TYPE=Release ..</br>
make -j32 (You may leave out the -j option it just tells make how many cores it may use.)</br> </code>



## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.  

Please do not reformat the source code for the existing code.  If you make additions, go ahead and format 
the source files as you like.

Please make sure to update tests as appropriate.

## License
[Apache 2.0](http://www.apache.org/licenses/LICENSE-2.0)
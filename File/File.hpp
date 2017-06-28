/*
 The MIT License (MIT)
 
 Copyright (c) 2017 Daniel Illescas Romero
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
*/

#pragma once

#include <fstream>
#include <string>

namespace evt {
	
	class File {
		
	public:
		
		enum Mode {
			binary,
			normal,
			both
		};
		
	private:
		
		std::fstream fileStream;
		std::ios_base::openmode inputOutputMode;
		std::string fileName;
		Mode mode = Mode::both;
		
		void open(const std::ios_base::openmode inputOutputMode) {
			
			if (this->inputOutputMode != inputOutputMode) {
				
				close();
				this->inputOutputMode = inputOutputMode;
				fileStream.open(fileName, inputOutputMode);
				
				if (fileStream.fail()) {
					std::cerr << "File couldn't be open" << std::endl;
				}
			}
		}
		
		void close() {
			if (fileStream.is_open()) {
				fileStream.close();
			}
		}
		
		void incompatibleMode() {
			std::cerr << "Error: Incompatible Mode" << std::endl;
		}
		
	public:
		
		// Only for binary files
		bool writeAtEnd = true;
		
		File(const std::string& fileName, const Mode mode = Mode::both) {
			this->fileName = fileName;
			this->mode = mode;
		}
		
		/* BINARY */
		
		template <typename Type, typename = typename std::enable_if<std::is_same<Type, std::string>::value>::type>
		void writeInBinary(const Type& text) {
			
			if (mode == Mode::normal) { incompatibleMode(); return; }
			
			if (writeAtEnd) { open(std::ios::binary | std::ios::out | std::ios::in | std::ios::app);
			} else { open(std::ios::binary | std::ios::out | std::ios::in); }
			fileStream.write(text.c_str(), text.length());
		}
		
		template <typename Type, typename = typename std::enable_if<!std::is_same<Type, std::string>::value>::type>
		void writeInBinary(Type contentToWrite) {
			
			if (mode == Mode::normal) { incompatibleMode(); return; }
			
			if (writeAtEnd) { open(std::ios::binary | std::ios::out | std::ios::in | std::ios::app);
			} else { open(std::ios::binary | std::ios::out | std::ios::in); }
			fileStream.write(reinterpret_cast<char*>(&contentToWrite), sizeof(contentToWrite));
		}
		
		template <typename Type, typename = typename std::enable_if<!std::is_same<Type, std::string>::value>::type>
		Type readFromBinary() {
			
			if (mode == Mode::normal) { incompatibleMode(); return Type{}; }
			
			Type readInput {};
			open(std::ios::in | std::ios::binary);
			fileStream.read(reinterpret_cast<char*>(&readInput), sizeof(readInput));
			return readInput;
		}
		
		template <typename Type, typename = typename std::enable_if<std::is_same<Type, std::string>::value>::type>
		Type readFromBinary(std::size_t size) {
			
			if (mode == Mode::normal) { incompatibleMode(); return Type{}; }
			
			open(std::ios::in | std::ios::binary);
			
			std::unique_ptr<char> readTextChar(new char[size]);
			fileStream.read(readTextChar.get(), size);
			
			return readTextChar.get();
		}
		
		void seekPosition(std::size_t offsetPosition, std::ios_base::seekdir position = std::ios::beg) {
			
			if (mode == Mode::normal) { incompatibleMode(); return; }
			
			writeAtEnd = false;
			fileStream.seekp(offsetPosition, position);
		}
		
		/* TEXT */
		
		template <typename Type>
		void write(const Type& contentToWrite) {
			
			if (mode == Mode::binary) { incompatibleMode(); return; }
			
			open(std::ios::out | std::ios::in | std::ios::app);
			fileStream << contentToWrite;
		}
		
		// Reads text content word by word (?)
		std::string read() {
			
			if (mode == Mode::binary) { incompatibleMode(); return std::string{}; }
			
			std::string readContent;
			open(std::ios::in);
			fileStream >> readContent;
			
			return readContent;
		}
		
		std::string getline() {
			
			if (mode == Mode::binary) { incompatibleMode(); return std::string{}; }
			
			std::string s;
			
			open(std::ios::in);
			std::getline(fileStream, s);
			
			return s;
		}
		
		std::string toString() {
			
			this->open(std::ios::in);
			
			std::string outputContent;
			
			while(!fileStream.eof()) {
				outputContent += this->getline() + '\n';
			}
			
			return outputContent;
		}
		
		static std::string toString(const std::string& fileName) {
			File fileToRead(fileName);
			return fileToRead.toString();
		}
		
		static void saveTextTo(const std::string& fileName, const std::string& text) {
			File fileToWrite(fileName);
			fileToWrite.open(std::ios::out);
			fileToWrite.write(text);
		}
		
		/* OTHER */
		
		void seekInputPosition(std::size_t offsetPosition, std::ios_base::seekdir position = std::ios::beg) {
			fileStream.seekg(offsetPosition, position);
		}
		
		void open(const std::string& fileName, const Mode mode = Mode::both) {
			this->fileName = fileName;
			this->mode = mode;
			this->close();
		}
		
		std::string getFileName() const {
			return fileName;
		}
		
		~File() {
			close();
		}
	};
}

#include "ResourceHolder.h"
namespace BaseFramework
{
	ResourceHolder::ResourceHolder() : fonts("Fonts", "ttf"), textures("Textures", "png"), soundBuffers("Audio", "ogg")
	{
	}
	ResourceHolder& ResourceHolder::getInstance()
	{
		static ResourceHolder holder;
		return holder;
	}
}
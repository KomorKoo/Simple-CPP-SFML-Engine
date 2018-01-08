#include "ResourceHolder.hpp"

ResourceHolder& ResourceHolder::get() {
	static ResourceHolder rs;

	return rs;
}

ResourceHolder::ResourceHolder()
:	textures("Textures", "png")
,	sounds	("SFX", "ogg")
,	fonts	("Fonts", "ttf") {

	textures.addResource("dropMenuMotherButton");
	textures.addResource("dropMenuButton");
	fonts.addResource("Inconsolata");
}

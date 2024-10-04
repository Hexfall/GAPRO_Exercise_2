#include "TextRenderable.h"

TextRenderable::TextRenderable(GameObject *go)
    : Renderable(go), value() {}

void TextRenderable::SetValue(std::string s) {
    this->value = s;
}

std::string TextRenderable::GetValue() {
    return this->value;
}

void TextRenderable::Render() {
    for (int i = 0; i < this->value.length(); i++)
        this->gameObject->engine->SetFrameChar(
                this->value.at(i),
                this->gameObject->loc_x + i,
                this->gameObject->loc_y
                );
}

void Renderable::Render() {}

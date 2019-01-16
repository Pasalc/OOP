#include "TAllocationBlock.h"
#include <iostream>

TAllocationBlock::TAllocationBlock(size_t size, size_t count):
_size(size), _count(count)
{
        _used_blocks=(char*)malloc(_size*_count);
        _free_blocks=(new TAllocationItem[_count]);
        for(size_t i=0;i<_count;i++){
            _free_blocks[i]=_size;
        }

        _free_count=_count;

        for(size_t i=0;i<_count;i++) _free_blocks[i]=_used_blocks+i*_size;
}

void* TAllocationBlock::allocate(){
    if(_free_count>0)
        return _free_blocks[--_free_count].GetMem();
    else{
        std::cout<<"Out of Bound\n";
        return nullptr;
    }
}

void TAllocationBlock::deallocate(void *pointer){
    _free_blocks[_free_count++]=(char*)pointer;
}

bool TAllocationBlock::has_free_blocks(){
    return _free_count>0;
}

TAllocationBlock::~TAllocationBlock(){
    delete _used_blocks;
    delete _free_blocks;
}


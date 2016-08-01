//
//  main.cpp
//  leveldb
//
//  Created by richard on 16/8/1.
//  Copyright © 2016年 richard. All rights reserved.
//
#include "leveldb/db.h"
#include <iostream>
#include <cassert>

int main(){
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());
    leveldb::Slice key1 = "hello";
    leveldb::Slice key2 = "world";
    std::string value;
    db->Put(leveldb::WriteOptions(), key1, "world");
    leveldb::Status s = db->Get(leveldb::ReadOptions(), key1, &value);
    if (s.ok()) {
        s = db->Put(leveldb::WriteOptions(), key2, value);
        std::string value2;
        db->Get(leveldb::ReadOptions(), key2, &value2);
        std::cout<<value2<<std::endl;
    }
    if (s.ok()) s = db->Delete(leveldb::WriteOptions(), key1);
    delete db;
    return 0;
}
FJKit - NSDictionary
=====

I love working with JSON and Objective-C is often very strict with what you can do on NSDictionaries. You know how document oriented databases can be messy. If you call "valueForKeyPath" on some dictionary that doesn't contain the key, it will simply crash your app. This category resolves it and simply returns nil.

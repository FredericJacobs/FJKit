//
//  NSDictionary+stable.m
//  Storify
//
//  Created by Frederic Jacobs on 1/11/12.
//  Copyright (c) 2012 Frederic Jacobs. All rights reserved.
//

#import "NSDictionary+stable.h"

@implementation NSDictionary (stable)

- (id)valueForKeyPath:(NSString *)keyPath{
    
    NSArray *parameters = [keyPath componentsSeparatedByString:@"."];
    
    NSDictionary *tempObject = [self objectForKey:[parameters objectAtIndex:0]];
    
    for (int i = 1 ; i < [parameters count]; i++) {
        if ([tempObject respondsToSelector:NSSelectorFromString([NSString stringWithFormat:@"objectForKey:"])]) {
            tempObject = [tempObject objectForKey:[parameters objectAtIndex:i]];
        }
        else {
            return nil;
        }
    }
    
    return tempObject;
    
}

@end

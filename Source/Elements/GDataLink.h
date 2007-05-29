/* Copyright (c) 2007 Google Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

//
//  GDataLink.h
//

#import <Cocoa/Cocoa.h>

#import "GDataObject.h"


#undef _EXTERN
#undef _INITIALIZE_AS
#ifdef GDATALINK_DEFINE_GLOBALS
#define _EXTERN 
#define _INITIALIZE_AS(x) =x
#else
#define _EXTERN extern
#define _INITIALIZE_AS(x)
#endif

_EXTERN NSString* kGDataLinkRelFeed _INITIALIZE_AS(@"http://schemas.google.com/g/2005#feed");
_EXTERN NSString* kGDataLinkRelPost _INITIALIZE_AS(@"http://schemas.google.com/g/2005#post");
_EXTERN NSString* kGDataLinkRelBatch _INITIALIZE_AS(@"http://schemas.google.com/g/2005#batch");

_EXTERN NSString* kGDataLinkTypeAtom _INITIALIZE_AS(@"application/atom+xml");

// for links, like <link rel="alternate" type="text/html"
//     href="http://www.google.com/calendar/event?eid=b..." title="alternate"/>
@interface GDataLink : GDataObject <NSCopying, GDataExtension> {
  NSString *rel_;
  NSString *type_;
  NSString *href_;
  NSString *hrefLang_;
  NSString *title_;
  NSString *titleLang_;
  NSNumber *resourceLength_;
}

+ (GDataLink *)linkWithRel:(NSString *)rel
                      type:(NSString *)type
                      href:(NSString *)href;  // parameters may be nil

- (id)initWithXMLElement:(NSXMLElement *)element
                  parent:(GDataObject *)parent;

- (NSXMLElement *)XMLElement;

- (NSString *)rel;
- (void)setRel:(NSString *)str;
- (NSString *)type;
- (void)setType:(NSString *)str;
- (NSString *)href;
- (void)setHref:(NSString *)str;
- (NSString *)hrefLang;
- (void)setHrefLang:(NSString *)str;
- (NSString *)title;
- (void)setTitle:(NSString *)str;
- (NSString *)titleLang;
- (void)setTitleLang:(NSString *)str;
- (NSNumber *)resourceLength;
- (void)setResourceLength:(NSNumber *)length;

// convenience method

// convert the href string into an URL
- (NSURL *)URL;

// utility method

// get a list of short names for links in the array
+ (NSArray *)linkNamesFromLinks:(NSArray *)links;
@end

@interface NSArray(GDataLinkArray)
// utilities for extraacting a GDataLink from an array of links
- (GDataLink *)linkWithRelAttributeValue:(NSString *)rel;
- (GDataLink *)linkWithRelAttributeSuffix:(NSString *)relSuffix;

- (GDataLink *)feedLink;
- (GDataLink *)postLink;
- (GDataLink *)editLink;
- (GDataLink *)mediaEditLink;
- (GDataLink *)alternateLink;
- (GDataLink *)selfLink;
- (GDataLink *)nextLink;
- (GDataLink *)previousLink;
- (GDataLink *)batchLink;
@end
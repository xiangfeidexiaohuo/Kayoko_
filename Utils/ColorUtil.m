//
//  ColorUtil.m
//  Kayoko
//
//  Created by Alexandra Aurora Göttlicher
//

#import "ColorUtil.h"

@implementation ColorUtil
/**
 * Creates a color object from a hex string.
 *
 * @param hex The hex string.
 *
 * @return The color object.
 */
+ (UIColor *)getColorFromHex:(NSString *)hex {
    if ([hex length] == 4) {
        hex = [NSString stringWithFormat:@"#%@%@%@%@%@%@", [hex substringWithRange:NSMakeRange(1, 1)], [hex substringWithRange:NSMakeRange(1, 1)], [hex substringWithRange:NSMakeRange(2, 1)], [hex substringWithRange:NSMakeRange(2, 1)], [hex substringWithRange:NSMakeRange(3, 1)], [hex substringWithRange:NSMakeRange(3, 1)]];
    }

    unsigned rgbValue = 0;
    NSScanner* scanner = [NSScanner scannerWithString:hex];
    [scanner setScanLocation:1];
    [scanner scanHexInt:&rgbValue];

    return [UIColor colorWithRed:((rgbValue & 0xFF0000) >> 16) / 255 green:((rgbValue & 0xFF00) >> 8) / 255 blue:(rgbValue & 0xFF) / 255 alpha:1];
}

/**
 * Creates a color object from a RGB string.
 *
 * @param rgb The RGB string.
 *
 * @return The color object.
 */
+ (UIColor *)getColorFromRgb:(NSString *)rgb {
    rgb = [rgb stringByReplacingOccurrencesOfString:@" " withString:@""];
    rgb = [rgb stringByReplacingOccurrencesOfString:@"rgb(" withString:@""];
    rgb = [rgb stringByReplacingOccurrencesOfString:@")" withString:@""];
    NSArray* rgbComponents = [rgb componentsSeparatedByString:@","];
    return [UIColor colorWithRed:[rgbComponents[0] floatValue] / 255 green:[rgbComponents[1] floatValue] / 255 blue:[rgbComponents[2] floatValue] / 255 alpha:1];
}

/**
 * Creates a color object from a RGBA string.
 *
 * @param rgba The RGBA string.
 *
 * @return The color object.
 */
+ (UIColor *)getColorFromRgba:(NSString *)rgba {
    rgba = [rgba stringByReplacingOccurrencesOfString:@" " withString:@""];
    rgba = [rgba stringByReplacingOccurrencesOfString:@"rgba(" withString:@""];
    rgba = [rgba stringByReplacingOccurrencesOfString:@")" withString:@""];
    NSArray* rgbaComponents = [rgba componentsSeparatedByString:@","];
    return [UIColor colorWithRed:[rgbaComponents[0] floatValue] / 255 green:[rgbaComponents[1] floatValue] / 255 blue:[rgbaComponents[2] floatValue] / 255 alpha:[rgbaComponents[3] floatValue]];
}
@end

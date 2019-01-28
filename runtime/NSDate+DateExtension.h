//
//  NSDate+DateExtension.h
//  BPG_dateDemo
//
//  Created by baipeng on 2017/6/6.
//  Copyright © 2017年 BPG. All rights reserved.
//

#import <Foundation/Foundation.h>
#define D_MINUTE	60
#define D_HOUR		3600
#define D_DAY		86400
#define D_WEEK		604800
#define D_YEAR		31556926

static NSString * const dateDefulatTimeFormat = @"yyyy-MM-dd HH:mm:ss";//默认
static NSString * const dateYMdHmTimeFormat = @"yyyy年MM月dd日 HH:mm";
static NSString * const dateYMdHmsSZTimeFormat = @"yyyy-MM-dd HH:mm:ss.SSS Z";
static NSString * const dateYMdHmsTimeFormat = @"yyyy/MM/dd HH:mm:ss";


@interface NSDate (DateExtension)
#pragma mark - 更新日历实时
+ (NSCalendar *) currentCalendar;

#pragma mark -  Pullic Class -------
/**
 @param format 日期样式
 @return 获取当前时间
 */
+ (NSDate *) dateTadyWithFormat:(NSString *)format;
/**
 @return 获取后天时间
 */
+ (NSDate *) dateTomorrow;
/**
 @return 获取昨天时间
 */
+ (NSDate *) dateYesterday;
/**
 @param days 天数
 @return 几天后
 */
+ (NSDate *) dateWithDaysFromNow: (NSInteger) days;
/**
 @param days 天数
 @return 几天后
 */
+ (NSDate *) dateWithDaysBeforeNow: (NSInteger) days;
/**
 @param dHours 小时
 @return 几小时后
 */
+ (NSDate *) dateWithHoursFromNow: (NSInteger) dHours;
/**
 @param dHours 小时
 @return 几小时前
 */
+ (NSDate *) dateWithHoursBeforeNow: (NSInteger) dHours;
/**
 @param dMinutes 分钟
 @return 几分钟后
 */
+ (NSDate *) dateWithMinutesFromNow: (NSInteger) dMinutes;
/**
 @param dMinutes 分钟
 @return 几分钟前
 */
+ (NSDate *) dateWithMinutesBeforeNow: (NSInteger) dMinutes;
/**
 @param timeInterVal timeInterVal
 @param sinceDate 时间样式 yyyy年MM月dd日  HH:mm
 @return return  延迟时间 几分钟后
 */
+ (NSDate *)addDateSinceDateTimeInterVal:(NSTimeInterval)timeInterVal withSinceDate:(NSDate *)sinceDate;
/**
 @param datestr 日期
 @param format 格式
 @return 日期字符串返回date
 */
+ (NSDate *)date:(NSString *)datestr WithFormat:(NSString *)format;

#pragma mark ---------------------返回NSStirng---------------------------
/**
 @param date 日期
 @param format 格式
 @return date返回字符串日期
 */
+ (NSString *)stringFromDate:(NSDate *)date Format:(NSString *)format;
/**
 @param timeString 时间戳
 @param format 格式
 @return 时间戳转字符串时间
 */
+ (NSString *)dealTime:(NSString *)timeString dateFormatter:(NSString *)format;
/**
 @param originalTime 原时间字符串
 @param originalFormat 原格式
 @param resultsFormat 转换后时间格式
 @return 时间格式替换
 */
+ (NSString *)conversionOriginalTime:(NSString *)originalTime
                  withOriginalFormat:(NSString *)originalFormat
                   withResultsFormat:(NSString *)resultsFormat;
/**
 @param originalDate 时间date
 @return 时间戳
 */
+ (NSString *)getTimeStampFromOriginalTime:(NSDate *)originalDate;
/**
 @param second 时间秒数  逢60s加1分钟
 @return 字符串 分秒 计时器
 */
+ (NSString *)convertTimeToString:(NSInteger)second;
/**
 @param duration 时间秒数
 @return 1h00‘00’ 时分秒 计时器
 */
+ (NSString *)dealTimeDuration:(unsigned long long) duration;
/**
 @param beTime 时间戳 毫秒
 @return 多少时分秒前 自定义
 */
+ (NSString *)distanceTimeWithBeforeTime:(double)beTime;
/**
 @param durationString 时间戳 毫秒
 @param zeroString 默认 时间为0
 @param firstString 多少时分秒 自定义 “还有” “距离”
 @return 返回多少时间。。。。。
 */
+ (NSString *)dealLimitedTimeWithDuration:(NSString *)durationString
                          withDefaultZero:(NSString *)zeroString
                          withFirstString:(NSString *)firstString;








#pragma mark --- prviate Class ---------


/**
 @param dateStyle 日期样式
 @param timeStyle 时间样式
 @return 时间系统格式
 */
- (NSString *) stringWithDateStyle: (NSDateFormatterStyle) dateStyle timeStyle: (NSDateFormatterStyle) timeStyle;
/**
 @param format 日期
 @return 属性 返回日期字符串
 */
- (NSString *) stringWithFormat: (NSString *) format;
/**
 6/7/17, 2:14 PM
 */
@property (nonatomic, readonly) NSString *shortString;
/**
 6/7/17
 */
@property (nonatomic, readonly) NSString *shortDateString;
/**
 2:14 PM
 */
@property (nonatomic, readonly) NSString *shortTimeString;
/**
 Jun 7, 2017, 2:14:25 PM
 */
@property (nonatomic, readonly) NSString *mediumString;
/**
 Jun 7, 2017
 */
@property (nonatomic, readonly) NSString *mediumDateString;
/**
 2:14:25 PM
 */
@property (nonatomic, readonly) NSString *mediumTimeString;
/**
 June 7, 2017 at 2:14:25 PM GMT+8
 */
@property (nonatomic, readonly) NSString *longString;
/**
 June 7, 2017
 */
@property (nonatomic, readonly) NSString *longDateString;
/**
  2:14:25 PM GMT+8
 */
@property (nonatomic, readonly) NSString *longTimeString;
/**
 @param aDate 时间属性
 @return 判断时间是否相同
 */
- (BOOL) isEqualToDateIgnoringTime: (NSDate *) aDate;

/**
 @return 判断是否今天
 */
- (BOOL) isToday;
/**
 @return 判断是否后天
 */
- (BOOL) isTomorrow;
/**
 @return 判断是否昨天
 */
- (BOOL) isYesterday;



#pragma mark - 判断 -- 星期 --- 月份 -- 年份 --- 
/**
 @param aDate 日期
 @return 判断是否这周7天里
 */
- (BOOL) isSameWeekAsDate: (NSDate *) aDate;
/**
  判断是否这星期
 */
- (BOOL) isThisWeek;
/**
  判断是否下星期
 */
- (BOOL) isNextWeek;
/**
  判断是否上星期
 */
- (BOOL) isLastWeek;
/**
 @param aDate 日期
 @return 判断是否这个月里
 */
- (BOOL) isSameMonthAsDate: (NSDate *) aDate;
/**
   判断是否这月份
 */
- (BOOL) isThisMonth;
/**
   判断是否下月份
 */
- (BOOL) isNextMonth;
/**
   判断是否上月份
 */
- (BOOL) isLastMonth;
/**
 @param aDate 日期
 @return 判断是否今年里
 */
- (BOOL) isSameYearAsDate: (NSDate *) aDate;
/**
 判断是否今年
 */
- (BOOL) isThisYear;
/**
 判断是否下一年
 */
- (BOOL) isNextYear;
/**
 判断是否上一年
 */
- (BOOL) isLastYear;
/**
 @param aDate 日期 比当前日期 大
 @return 判断是否早于某天,小于等于某天
 */
- (BOOL) isEarlierThanDate: (NSDate *) aDate;
/**
 @param aDate 日期 比 当前日期 小
 @return 判断是否晚于某天,大于等于某天
 */
- (BOOL) isLaterThanDate: (NSDate *) aDate;
/**
 判断当前日期是否未来
 */
- (BOOL) isInFuture;
/**
 判断当前时间是否过去
 */
- (BOOL) isInPast;
/**
 判断是否工作日
 */
- (BOOL) isTypicallyWorkday;
/**
 判断是否休息日
 */
- (BOOL) isTypicallyWeekend;

#pragma mark - Adjusting dates
/**
 @param dYears 年数
 @return 增加几年
 */
- (NSDate *) dateByAddingYears: (NSInteger) dYears;
/**
 @param dYears 年数
 @return 减少几年
 */
- (NSDate *) dateBySubtractingYears: (NSInteger) dYears;
/**
 @param dMonths 月数
 @return 增加月数
 */
- (NSDate *) dateByAddingMonths: (NSInteger) dMonths;
/**
 @param dMonths 月数
 @return 减少月数
 */
- (NSDate *) dateBySubtractingMonths: (NSInteger) dMonths;
/**
 @param dDays 天数
 @return 增加天数
 */
- (NSDate *) dateByAddingDays: (NSInteger) dDays;
/**
 @param dDays 天数
 @return 减少天数
 */
- (NSDate *) dateBySubtractingDays: (NSInteger) dDays;
/**
 @param dHours 小时
 @return 增加小时
 */
- (NSDate *) dateByAddingHours: (NSInteger) dHours;
/**
 @param dHours 小时
 @return 减少小时
 */
- (NSDate *) dateBySubtractingHours: (NSInteger) dHours;
/**
 @param dMinutes 分钟
 @return 增加分钟
 */
- (NSDate *) dateByAddingMinutes: (NSInteger) dMinutes;
/**
 @param dMinutes 分钟
 @return 减少分钟
 */
- (NSDate *) dateBySubtractingMinutes: (NSInteger) dMinutes;

/**
 1天前吗
 */
- (NSDate *) dateAtStartOfDay;
/**
 1天后吗
 */
- (NSDate *) dateAtEndOfDay;



// Retrieving intervals

/**
 多少分钟之后
 */
- (NSInteger) minutesAfterDate: (NSDate *) aDate;

/**
 多少分钟之前
 */
- (NSInteger) minutesBeforeDate: (NSDate *) aDate;
/**
 多少小时之后
 */
- (NSInteger) hoursAfterDate: (NSDate *) aDate;
/**
 多少小时之前
 */
- (NSInteger) hoursBeforeDate: (NSDate *) aDate;
/**
 多少天之后
 */
- (NSInteger) daysAfterDate: (NSDate *) aDate;
/**
多少天之前
 */
- (NSInteger) daysBeforeDate: (NSDate *) aDate;
/**
 距离今天几天，按天计算
 */
- (NSInteger)distanceInDaysToDate:(NSDate *)anotherDate;

// Decomposing dates 获取年月日 是坟墓
@property (readonly) NSInteger nearestHour;
@property (readonly) NSInteger hour;
@property (readonly) NSInteger minute;
@property (readonly) NSInteger seconds;
@property (readonly) NSInteger day;
@property (readonly) NSInteger month;
@property (readonly) NSInteger week;
@property (readonly) NSInteger weekday;
@property (readonly) NSInteger nthWeekday; // e.g. 2nd Tuesday of the month == 2
@property (readonly) NSInteger year;

/**
 1天前 返回时间
 */
- (NSDate *)dateWithYMD;
/**
 @param formatter 格式
 @return 时间 格林尼治时间 减8小时 废弃
 */
- (NSDate *)dateWithFormatter:(NSString *)formatter;















@end
